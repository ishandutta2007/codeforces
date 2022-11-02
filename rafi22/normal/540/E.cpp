#include <bits/stdc++.h>

#define int long long
#define double long double
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

int pot=1<<30;
struct node
{
    int val;
    struct node *L;
    struct node *R;
};
struct node* Newnode()
{
    struct node* xd = new struct node;
    xd->val=0;
    xd->L=NULL;
    xd->R=NULL;
    return xd;
}
struct node* root=NULL;
int que(node *v,int a,int b,int l,int r)
{
    if(a<=l&&b>=r) return v->val;
    if(l>b||r<a) return 0;
    if(v->L==NULL) v->L=Newnode();
    if(v->R==NULL) v->R=Newnode();
    return que(v->L,a,b,l,(l+r)/2)+que(v->R,a,b,(l+r)/2+1,r);
}
void ins(node *v,int a,int l,int r)
{
    v->val++;
    if(l==r) return;
    if(a<=(l+r)/2)
    {
        if(v->L==NULL) v->L=Newnode();
        ins(v->L,a,l,(l+r)/2);
    }
    else
    {
        if(v->R==NULL) v->R=Newnode();
        ins(v->R,a,(l+r)/2+1,r);
    }
}

map<int,int>pos;
int arr[200007];
pair<int,int>ord[200007];
int it=0;

int fenwick[200007];
inline void ins1(int x,int val) {while(x<=it)  {  fenwick[x]+=val;  x+=(x&-x);  } }
inline int que1(int x) {int res=0;  while(x>0)  {  res+=fenwick[x];  x-=(x&-x);  } return res; }

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
        int n;
        cin>>n;
        while(n--)
        {
            int a,b;
            cin>>a>>b;
            if(pos[a]==0)
            {
                pos[a]=a;
                arr[++it]=a;
            }
            if(pos[b]==0)
            {
                pos[b]=b;
                arr[++it]=b;
            }
            swap(pos[a],pos[b]);
        }
        sort(arr+1,arr+1+it);
        root=Newnode();
        for(int i=1;i<=it;i++)
        {
            ins(root,arr[i],1,pot);
            ord[i]={pos[arr[i]],i};
        }
        sort(ord+1,ord+1+it);
        int ans=0;
        for(int i=1;i<=it;i++)
        {
            ans+=que1(it)-que1(ord[i].nd);
            ins1(ord[i].nd,1);
        }
        for(int i=1;i<=it;i++)
        {
            if(pos[arr[i]]>arr[i]) ans+=pos[arr[i]]-arr[i]-1-que(root,arr[i]+1,pos[arr[i]]-1,1,pot);
            else if(pos[arr[i]]<arr[i]) ans+=arr[i]-pos[arr[i]]-1-que(root,pos[arr[i]]+1,arr[i]-1,1,pot);
        }
        cout<<ans<<endl;


    }

    return 0;
}