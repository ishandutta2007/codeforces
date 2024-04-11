#include <bits/stdc++.h>

#define int long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

struct node
{
    int a,b;
    struct node *L;
    struct node *R;
};
struct node* Newnode()
{
    struct node* xd = new struct node;
    xd->a=-mod;
    xd->b=-inf;
    xd->L=NULL;
    xd->R=NULL;
    return xd;
}
struct node* root=NULL;

pair<pair<int,int>,int>P[1000007];
int DP[1000007],pot=1073741824;
int val[1000007];

void ins(node *v,int l,int r,int na,int nb)
{
    if(l>r||(na<=v->a&&nb<=v->b)) return;
   // cout<<l<<" "<<r<<" "<<na<<" "<<nb<<endl;
    ld x=(ld)(nb-v->b)/(ld)(v->a-na);
  //  cout<<x<<endl;
    swap(v->a,na);
    swap(v->b,nb);
    if(na<=v->a&&nb<=v->b) return;
    if(v->L==NULL) v->L=Newnode();
    if(v->R==NULL) v->R=Newnode();
    if(na>v->a)
    {
        if(x<=(l+r)/2) ins(v->L,l,(l+r)/2,na,nb);
        else ins(v->R,(l+r)/2+1,r,na,nb);
    }
    else
    {
        if(x<=(l+r)/2) ins(v->R,(l+r)/2+1,r,na,nb);
        else ins(v->L,l,(l+r)/2,na,nb);
    }
}
int que(node *v,int l,int r,int i)
{
    if(l>r||i<l||i>r) return -inf;
    if(v->L==NULL) v->L=Newnode();
    if(v->R==NULL) v->R=Newnode();
    if(l==r) return v->a*i+v->b;
    return max(v->a*i+v->b,max(que(v->L,l,(l+r)/2,i),que(v->R,(l+r)/2+1,r,i)));
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>P[i].st.st>>P[i].st.nd>>P[i].nd;
        sort(P+1,P+n+1);
        vector<pair<int,int>>vec;
        vec.pb({0,0});
        for(int i=1;i<=n;i++)
        {
            int l=0,r=sz(vec)-1,sr,res=0;
            while(l<=r)
            {
                sr=(l+r)/2;
                if(sr==sz(vec)-1)
                {
                    res=max(res,vec[sr].st*P[i].st.nd+vec[sr].nd);
                    break;
                }
                if(vec[sr].st*P[i].st.nd+vec[sr].nd>=vec[sr+1].st*P[i].st.nd+vec[sr+1].nd)
                {
                    res=max(res,vec[sr].st*P[i].st.nd+vec[sr].nd);
                    r=sr-1;
                }
                else
                {
                    res=max(res,vec[sr+1].st*P[i].st.nd+vec[sr+1].nd);
                    l=sr+1;
                }
            }
            DP[i]=res+P[i].st.st*P[i].st.nd-P[i].nd;
            vec.pb({-P[i].st.st,DP[i]});
            while(sz(vec)>2)
            {
                ld x=(ld)(vec[sz(vec)-1].nd-vec[sz(vec)-3].nd)/(ld)(vec[sz(vec)-3].st-vec[sz(vec)-1].st);
                ld x1=(ld)(vec[sz(vec)-2].nd-vec[sz(vec)-3].nd)/(ld)(vec[sz(vec)-3].st-vec[sz(vec)-2].st);
                if(x>x1)
                {
                    vec.pop_back();
                    vec.pop_back();
                    vec.pb({-P[i].st.st,DP[i]});
                }
                else break;
            }
            ans=max(ans,DP[i]);
        }
       // cout<<endl;
        cout<<ans;
    }

    return 0;
}