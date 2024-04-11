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

const int N=1e5+5;
vector<int> par(N);
int find(int tr){return tr==par[tr]?tr:par[tr]=find(par[tr]);}
void merge(int a,int b){par[find(a)]=find(b);}
int main()
{
    //freopen("in.txt","r",stdin);
	int t;
	scanf("%i",&t);
	while(t--){
        int n;
        scanf("%i",&n);
        for(int i=0;i<n;i++)
            par[i]=i;
        vector<int> s1(n,-1),s2(n,-1);
        queue<int> leaf;
        vector<multiset<pair<int,int> > > s(n);
        map<vector<int>,int> indeks;
        for(int i=2;i<n;i++){
            int a,b,c;
            scanf("%i %i %i",&a,&b,&c);
            a--;b--;c--;
            vector<int> in={a,b,c};
            sort(all(in));
            indeks[in]=i-1;
            s[a].insert({min(b,c),max(b,c)});
            s[b].insert({min(a,c),max(a,c)});
            s[c].insert({min(b,a),max(b,a)});
        }
        for(int i=0;i<n;i++)
            if(s[i].size()==1)
                leaf.push(i);
        vector<int> qq;
        while(qq.size()<n-2){
            int tr=leaf.front();
            leaf.pop();
            auto pp=*s[tr].begin();
            int a=tr,b=pp.f,c=pp.s;
            //printf("%i %i %i\n",a+1,b+1,c+1);
            vector<int> aaa={a,b,c};
            sort(all(aaa));
            qq.pb(indeks[aaa]);
            if(s1[a]==-1){
                if(s1[b]==-1&&find(b)!=find(a)){
                    s1[b]=a;
                    s1[a]=b;
                    merge(a,b);
                }else{
                    if(s2[b]==-1&&find(b)!=find(a)){
                        s2[b]=a;
                        s1[a]=b;
                        merge(a,b);
                    }else{
                        if(s1[c]==-1&&find(c)!=find(a)){
                            s1[c]=a;
                            s1[a]=c;
                            merge(a,c);
                        }else{
                            if(s2[c]==-1&&find(c)!=find(a)){
                                s2[c]=a;
                                s1[a]=c;
                                merge(a,c);
                            }
                        }
                    }
                }
            }
            if(s2[a]==-1){
                if(s1[b]==-1&&find(b)!=find(a)){
                    s1[b]=a;
                    s2[a]=b;
                    merge(a,b);
                }else{
                    if(s2[b]==-1&&find(b)!=find(a)){
                        s2[b]=a;
                        s2[a]=b;
                        merge(a,b);
                    }else{
                        if(s1[c]==-1&&find(c)!=find(a)){
                            s1[c]=a;
                            s2[a]=c;
                            merge(a,c);
                        }else{
                            if(s2[c]==-1&&find(c)!=find(a)){
                                s2[c]=a;
                                s2[a]=c;
                                merge(a,c);
                            }
                        }
                    }
                }
            }
            s[a].erase(s[a].find({min(b,c),max(b,c)}));
            s[b].erase(s[b].find({min(a,c),max(a,c)}));
            s[c].erase(s[c].find({min(b,a),max(b,a)}));
            if(s[b].size()==1)
                leaf.push(b);
            if(s[c].size()==1)
                leaf.push(c);
        }
        vector<int> done(n);
        int start=0;
        for(int i=0;i<n;i++)
            if(s1[i]==-1||s2[i]==-1)
                start=i;
        for(int i=0;i<n;i++){
            printf("%i ",start+1);
            done[start]=1;
            if(s1[start]!=-1&&done[s1[start]]==0)
                done[s1[start]]=1,start=s1[start];
            else
                if(s2[start]!=-1&&done[s2[start]]==0)
                    done[s2[start]]=1,start=s2[start];
        }
        printf("\n");
        for(auto p:qq)
            printf("%i ",p);
        printf("\n");
	}
    return 0;
}