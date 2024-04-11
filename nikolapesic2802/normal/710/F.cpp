#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define D(x) cerr << #x << " is " << (x) << "\n";

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

struct node{
    vector<int> nxt;
    vector<int> ends,sl;
    int fail;
};
struct AhoCorasick{
    vector<node> aho;
    vector<string> strings;
    string trq;
    int newNode()
    {
        node a;
        a.nxt.resize(26,-1);
        a.fail=0;
        aho.pb(a);
        return aho.size()-1;
    }
    void addString(int pos,int ind,int tr)
    {
        if(pos==(int)strings[ind].size()){
            aho[tr].ends.pb(ind);
            return;
        }
        int sl=strings[ind][pos]-'a';
        if(aho[tr].nxt[sl]==-1){
            int a=newNode();
            aho[tr].nxt[sl]=a;
        }
        addString(pos+1,ind,aho[tr].nxt[sl]);
    }
    void bfs(){
        aho[0].fail=-1;
        queue<int> q;
        for(int i=0;i<26;i++)
            if(aho[0].nxt[i]!=-1)
                q.push(aho[0].nxt[i]);
        while(q.size())
        {
            int tr=q.front();
            q.pop();
            for(int i=0;i<26;i++)
            {
                if(aho[tr].nxt[i]==-1)
                    continue;
                q.push(aho[tr].nxt[i]);
                int tren=aho[tr].fail;
                while(true)
                {
                    if(aho[tren].nxt[i]!=-1)
                    {
                        aho[aho[tr].nxt[i]].fail=aho[tren].nxt[i];
                        for(auto p:aho[aho[tren].nxt[i]].ends)
                            aho[aho[tr].nxt[i]].ends.pb(p);
                        aho[aho[tren].nxt[i]].sl.pb(aho[tr].nxt[i]);
                        break;
                    }
                    if(aho[tren].fail==-1)
                        break;
                    tren=aho[tren].fail;
                }
            }
        }
    }
    void clear()
    {
        aho.clear();
        strings.clear();
        trq.clear();
    }
    void construct(vector<string> str){
        clear();
        strings=str;
        newNode();
        for(int i=0;i<(int)strings.size();i++)
            addString(0,i,0);
        bfs();
    }
    int calc(int pos,int tr)
    {
        if(pos==(int)trq.size())
            return aho[tr].ends.size();
        int tren=tr;
        int sl=trq[pos]-'a';
        while(true)
        {
            if(aho[tren].nxt[sl]!=-1)
                return aho[tr].ends.size()+calc(pos+1,aho[tren].nxt[sl]);
            if(tren==0)
                return aho[tr].ends.size()+calc(pos+1,0);
            tren=aho[tren].fail;
        }
        assert(0);
    }
    int getAns(string s)
    {
        trq=s;
        return calc(0,0);
    }
};
struct trick{
    vector<AhoCorasick> aho;
    vector<bool> used;
    trick(){aho.resize(20);used.resize(20);}
    void add(vector<string> strings,int pos=0)
    {
        if(used[pos])
        {
            for(auto p:aho[pos].strings)
                strings.pb(p);
            aho[pos].clear();
            used[pos]=0;
            add(strings,pos+1);
        }
        else
            aho[pos].construct(strings),used[pos]=1;
    }
    int getAns(string s)
    {
        int ans=0;
        for(int i=0;i<20;i++)
            if(used[i])
                ans+=aho[i].getAns(s);
        return ans;
    }
};
int main()
{
    int n;
    scanf("%i",&n);
    trick add,sub;
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%i",&t);
        string s;
        cin >> s;
        if(t==1)
            add.add({s});
        if(t==2)
            sub.add({s});
        if(t==3)
            printf("%i\n",add.getAns(s)-sub.getAns(s)),fflush(stdout);
    }
    return 0;
}