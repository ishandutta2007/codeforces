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

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
#define bt bitset<1000>
#define add(x) ((x)&mask)!=0
struct operacija{
    int type;
    bt val;
    string name,prvi,drugi,op;
};
vector<operacija> operacije;
unordered_map<string,int> value;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n,m;
	cin >> n >> m;
	//scanf("%i %i",&n,&m);
	for(int i=0;i<n;i++)
    {
        string name,op,prvi,drugi;
        cin >> name >> op >> prvi;
        operacija tr;
        tr.name=name;
        if(prvi[0]=='0'||prvi[0]=='1')
        {
            tr.type=1;
            tr.val=bt(prvi);
        }
        else
        {
            tr.type=2;
            cin >> op >> drugi;
            tr.prvi=prvi;
            tr.drugi=drugi;
            tr.op=op;
        }
        operacije.pb(tr);
    }
    bt minn,maxx;
    for(int pos=0;pos<m;pos++)
    {
        bt mask;
        mask[pos]=1;
        int up=0;
        int cnt0=0,cnt1=0;
        value.clear();
        for(auto p:operacije)
        {
            if(p.type==1)
            {
                cnt0+=add(p.val);
                value[p.name]=add(p.val);
            }
            else
            {
                int prvi,drugi;
                if(p.prvi[0]=='?')
                    prvi=up;
                else
                    prvi=value[p.prvi];
                if(p.drugi[0]=='?')
                    drugi=up;
                else
                    drugi=value[p.drugi];
                if(p.op[0]=='X')
                {
                    cnt0+=prvi^drugi;
                    value[p.name]=prvi^drugi;
                }
                if(p.op[0]=='O')
                {
                    cnt0+=prvi|drugi;
                    value[p.name]=prvi|drugi;
                }
                if(p.op[0]=='A')
                {
                    cnt0+=prvi&drugi;
                    value[p.name]=prvi&drugi;
                }
            }
        }
        up=1;
        value.clear();
        for(auto p:operacije)
        {
            if(p.type==1)
            {
                cnt1+=add(p.val);
                value[p.name]=add(p.val);
            }
            else
            {
                int prvi,drugi;
                if(p.prvi[0]=='?')
                    prvi=up;
                else
                    prvi=value[p.prvi];
                if(p.drugi[0]=='?')
                    drugi=up;
                else
                    drugi=value[p.drugi];
                if(p.op[0]=='X')
                {
                    cnt1+=prvi^drugi;
                    value[p.name]=prvi^drugi;
                }
                if(p.op[0]=='O')
                {
                    cnt1+=prvi|drugi;
                    value[p.name]=prvi|drugi;
                }
                if(p.op[0]=='A')
                {
                    cnt1+=prvi&drugi;
                    value[p.name]=prvi&drugi;
                }
            }
        }
        if(cnt0<=cnt1)
            minn[pos]=0;
        else
            minn[pos]=1;
        if(cnt0>=cnt1)
            maxx[pos]=0;
        else
            maxx[pos]=1;
    }
    for(int i=m-1;i>=0;i--)
        cout << (int)(minn[i]==1);
    cout << "\n";
    for(int i=m-1;i>=0;i--)
        cout << (int)(maxx[i]==1);
    cout << "\n";
    //cout << minn << endl << maxx << endl;
    return 0;
}