#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define VV vector
#define pb push_back
#define bitc  __builtin_popcountl
#define m_p make_pair
#define inf 200000000000000
#define MAXN 1000001
#define eps 0.0000000001
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
string char_to_str(char c){string tem(1,c);return tem;}
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();

//////////////

#define S second
#define F first
#define int long long  

/////////////
struct node
{
    int l,r;
    int v=0;
    int la=0;
    node* le,*ri;
    node(int a,int b)
    {
        l=a;
        v=0;
        la=0;
        r=b;
        le=NULL;
        ri=NULL;
    }
};
int qu(node* seg)
{
	if(seg==NULL)
		return 0;
	int m=(seg->l+seg->r)>>1;
	if(seg->la!=0)
	{
		if(seg->le==NULL)
		{
			seg->le=new node(seg->l,m);
		}
		if(seg->ri==NULL)
		{
			seg->ri=new node(m+1,seg->r);
		}
		seg->v+=seg->la;
		seg->le->la+=seg->la;
		seg->ri->la+=seg->la;
		seg->la=0;
	}
	return seg->v;
}
int up(node* seg,int lq,int rq,int val)
{
	// cout<<seg->l<<" "<<seg->r<<endl;
	int m=(seg->l+seg->r)>>1;
	if(seg->la!=0)
	{
		if(seg->le==NULL)
		{
			seg->le=new node(seg->l,m);
		}
		if(seg->ri==NULL)
		{
			seg->ri=new node(m+1,seg->r);
		}
		seg->v+=seg->la;
		seg->le->la+=seg->la;
		seg->ri->la+=seg->la;
		seg->la=0;
	}
    if(seg->l==lq&&rq==seg->r)
    {
    	seg->la+=val;
    	return seg->v+val;
    }
    else
    {
    	if(lq>m)
    	{
    		if(seg->ri==NULL)
    			seg->ri=new node(m+1,seg->r);
    		seg->v=max(qu(seg->le),up(seg->ri,lq,rq,val));
    	}
    	else
    	{
    		if(rq<=m)
    		{
    			if(seg->le==NULL)
	    			seg->le=new node(seg->l,m);
	    		seg->v=max(qu(seg->ri),up(seg->le,lq,rq,val));
    		}
    		else
    		{
    			if(seg->ri==NULL)
	    			seg->ri=new node(m+1,seg->r);
	    		if(seg->le==NULL)
	    			seg->le=new node(seg->l,m);
	    		seg->v=max(up(seg->ri,m+1,rq,val),up(seg->le,lq,m,val));
    		}
    	}
    	return seg->v;
    }
}

signed main()
{
	fastio;
	#ifdef ANIKET_GOYAL
		freopen("inputf.in","r",stdin);
		freopen("outputf.in","w",stdout);
	#endif
	int n,r;
	cin>>n>>r;
	pair<int,pair<int,int>> p[n];
	for(int i=0;i<n;++i)
	{
		cin>>p[i].S.F>>p[i].S.S;
		p[i].F=p[i].S.F+p[i].S.S;
	}
	sort(p,p+n);
	int i=0,j=0,k=0;
	node* seg=new node(-4000000,4000000);
	int ans=0;
	for(;i<n;++i)
	{
		while(j<n&&p[j].F-p[i].F<=2*r){
		// cout<<j<<endl;
			up(seg,p[j].S.F-p[j].S.S-r,p[j].S.F-p[j].S.S+r,1);
			++j;
		}
		ans=max(ans,seg->v);
		// cout<<i<<" "<<j<<"\n";
		// cout<<ans<<"\n";
		up(seg,p[i].S.F-p[i].S.S-r,p[i].S.F-p[i].S.S+r,-1);
	}
	cout<<ans;
}