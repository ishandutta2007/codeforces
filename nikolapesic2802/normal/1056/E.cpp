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

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
	os << '{';
	for(int i=0;i<sz(a);i++)
	{
		if(i>0&&i<sz(a)-1)
			os << ", ";
		os << a[i];
	}
	os << '}';
    return os;
}
const int mod=1e9+11;
const int N=1e6+5;
vector<int> p(N);
vector<int> lg(N);
const int M=22;
int sparce[N][M];
int find(int l,int r)
{
    int tr=l;
    int d=r-l+1;
    int h=0;
    for(int j=M-1;j>=0;j--)
    {
        if((1<<j)<=d)
        {
            d-=(1<<j);
            h=((ll)h+sparce[tr][j]*p[d])%mod;
            tr+=(1<<j);
        }
    }
    return h;
}
int main()
{
    p[0]=1;
    lg[1]=0;
    for(int i=1;i<N;i++)
    {
        p[i]=((ll)p[i-1]*27)%mod;
    }
    for(int i=2;i<N;i++)
    {
        lg[i]=lg[i/2]+1;
    }
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    string s,t;
    cin >> s;
    cin >> t;
    int n=s.size();
    int m=t.size();
    int num0=0,num1=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            num0++;
        }
        else
        {
            num1++;
        }
    }
    if(s[0]=='1'){
        swap(num0,num1);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
                s[i]='1';
            else
                s[i]='0';
        }
    }
    for(int i=0;i<m;i++)
    {
        sparce[i][0]=t[i]-'a'+1;
    }
    for(int j=1;j<M;j++)
    {
        for(int i=0;i<m;i++)
        {
            if(i+(1<<(j))-1<m)
            {
                sparce[i][j]=((ll)sparce[i][j-1]*p[(1<<(j))-1]+sparce[i+(1<<(j-1))][j-1])%mod;
            }
        }
    }
    int maxx=(m-num1)/(n-num1);
    int sol=0;
    for(int i=1;i<=maxx;i++)
    {
        //printf("Gledam %i\n",i);
        int tre=num0*i;
        int res=m-tre;
        if(res%num1)
            continue;
        int ss=res/num1;
        if(ss==0)
            continue;
        int tr=0;
        int h0=-1,h1=-1;
        bool test=true;
        for(int j=0;j<n;j++)
        {
            //printf("%i %i\n",h0,h1);
            if(s[j]=='0')
            {
                int h=find(tr,tr+i-1);
                if(h0==-1)
                    h0=h;
                else
                {
                    if(h0!=h||h0==h1){
                        test=false;
                        break;
                    }
                }
                tr+=i;
            }
            else
            {
                int h=find(tr,tr+ss-1);
                if(h1==-1)
                    h1=h;
                else
                {
                    if(h1!=h||h0==h1){
                        test=false;
                        break;
                    }
                }
                tr+=ss;
            }
        }
        if(test&&h0!=h1)
            sol++;
    }
    printf("%i\n",sol);
    /*for(int i=0;i<100;i++)
    {
        int l,r;
        scanf("%i %i",&l,&r);
        //printf("%i\n",find(l,r));
    }*/
    return 0;
}