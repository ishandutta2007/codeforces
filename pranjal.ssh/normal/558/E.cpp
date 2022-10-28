#include <bits/stdc++.h>
using namespace std;

#define INF 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) x.begin(), x.end()
#define tr(x,it) for(auto it = x.begin();it!=x.end();++it)
#define ntr(x,it) for(auto it = x.rbegin();it!=x.rend();++it)
#define sz(a) int((a).size()) 
#define pb push_back 
#define PB pop_back
#define pf push_front
#define PF pop_front
#define MP make_pair
#define clr clear
#define rz resize
#define C(a,b) memset(a,b,sizeof(a))
#define ia(a,n) FOR(i,0,n-1)cin>>a[i]
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,n) FOR(i,0,n-1)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
#define N 100001

int n,q;

int t[26][4*N];
int l[26][4*N];

void lazy(int id, int no, int sz)
{
    t[id][no]=sz*l[id][no];
    if(sz!=1)
    {
        l[id][2*no]=l[id][no];
        l[id][2*no+1]=l[id][no];
    }
    l[id][no]=-1;
}

int query(int id, int no, int i, int j, int qi, int qj)
{
    if(qi>qj)return 0;
    if(l[id][no]!=-1)lazy(id,no,j-i+1);
    
    if(i>j || j<qi || i>qj) return 0;
    
    if(i>=qi && j<=qj) return t[id][no];
    
    return query(id,2*no,i,(i+j)/2,qi,qj)+query(id,2*no+1,1+(i+j)/2,j,qi,qj);
}



void upd(int id, int no, int i, int j, int qi, int qj,int x)
{
    if(qi>qj)return ;
    if(l[id][no]!=-1)lazy(id,no,j-i+1);
    
    if(i>j || j<qi || i>qj) return;
    
    if(i>=qi && j<=qj)
    {
        l[id][no]=x;
        lazy(id,no,j-i+1);
        return;
    }
    
     upd(id,2*no,i,(i+j)/2,qi,qj,x); upd(id,2*no+1,1+(i+j)/2,j,qi,qj,x);
     t[id][no]=t[id][2*no]+t[id][2*no+1];
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin>>n>>q;
    string s;
    cin>>s;
    memset(l,-1,sizeof(l));
    tr(s,it)
    {
        int x=it-s.begin()+1;
        upd(*it-'a',1,1,n,x,x,1);
    }
    
    
        
    
    
    while(q--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        
        if(k==1)
        {
            int a[26],temp=0;
            FOR(i,0,25)a[i]=query(i,1,1,n,l,r);
            
            FOR(i,0,25)
            {
                upd(i,1,1,n,l,r,0);
                
                upd(i,1,1,n,l+temp,l+temp+a[i]-1,1);
                temp+=a[i];
            }
            
        }
        else
        {
            int a[26],temp=0;
            
            FOR(i,0,25)a[i]=query(i,1,1,n,l,r);
            NFOR(i,25,0)
            {
                upd(i,1,1,n,l,r,0);
            
                upd(i,1,1,n,l+temp,l+temp+a[i]-1,1);
                temp+=a[i];
            
            }
        }
        
    }
    //FOR()
    
    FOR(i,1,n)
    {
        FOR(j,0,25)
        {
            if(query(j,1,1,n,i,i))
            cout<<(char)((j+'a'));
        }
    }
    
    return 0;
}