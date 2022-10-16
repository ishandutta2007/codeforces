#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define f first
#define s second
#define all(x) x.begin(), x.end()

using namespace std;
using namespace __gnu_pbds;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const gp_hash_table<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	scanf("%i",&n);
	string s;
	cin >> s;
	vector<int> cnt(2);
	deque<int> str;
	for(auto p:s)
        if(p=='(')
            cnt[0]++,str.pb(1);
        else
            cnt[1]++,str.pb(-1);
    if(cnt[0]!=cnt[1])
    {
        printf("0\n1 1\n");
        return 0;
    }
    int shft=0;
    while(true)
    {
        int sum=0;
        bool uspeo=1;
        for(int i=0;i<n;i++)
        {
            sum+=str[i];
            if(sum<0)
            {
                shft+=i+1;
                uspeo=0;
                for(int j=0;j<=i;j++)
                    str.pb(str.front()),str.pop_front();
                break;
            }
        }
        if(uspeo)
            break;
    }
    /*for(auto p:str)
        if(p==1)
            printf("(");
        else
            printf(")");*/
    int mx=0,l=1,r=1,sum=0,tr,start;
    for(int i=0;i<n;i++)
    {
        if(sum==0)
        {
            start=i;
            tr=1;
        }
        sum+=str[i];
        if(str[i]==-1&&sum==1)
            tr++;
        if(sum==0)
            if(tr>mx)
                mx=tr,l=start,r=i;
    }
    int ukupno=0;
    int mx2=0,l2=1,r2=1;
    for(int i=0;i<n;i++)
    {
        if(sum==1&&str[i]==1)
        {
            start=i;
            tr=1;
        }
        sum+=str[i];
        if(sum==2&&str[i]==-1)
            tr++;
        if(sum==1&&str[i]==-1)
        {
            if(tr>mx2)
                mx2=tr,l2=start,r2=i;
        }
        if(sum==0)
            ukupno++;
    }
    if(ukupno+mx2>mx)
        mx=ukupno+mx2,l=l2,r=r2;
    printf("%i\n%i %i\n",mx,(l+shft)%n+1,(r+shft)%n+1);
    //cout << str << endl;
    return 0;
}