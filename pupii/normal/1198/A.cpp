    #include<bits/stdc++.h>
    #define il inline
    #define vd void
    #define int long long
    typedef long long ll;
    il ll gi(){
    	ll x=0,f=1;
    	char ch=getchar();
    	while(!isdigit(ch))f^=ch=='-',ch=getchar();
    	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    	return f?x:-x;
    }
    #ifdef mod
    il int pow(int x,int y){
    	int ret=1;
    	while(y){
    		if(y&1)ret=1ll*ret*x%mod;
    		x=1ll*x*x%mod;y>>=1;
    	}
    	return ret;
    }
    #endif
    int a[400010];
    signed main(){
    #ifdef XZZSB
    	//freopen("in.in","r",stdin);
    	//freopen("out.out","w",stdout);
    #endif
    	ll n=gi(),I=gi()*8,mxK=I/n;
    	if(mxK<0)return puts("0"),0;
    	mxK=std::min(30ll,mxK);
    	mxK=1<<mxK;
    	for(int i=1;i<=n;++i)a[i]=gi();
    	std::sort(a+1,a+n+1);
    	ll cnt=0,ans=1e9;
    	for(int l=1,r=0;l<=n;++l){
    		if(l>1&&a[l]!=a[l-1])--cnt;
    		while(r<n){
    			++r;
    			if(r==1||a[r-1]!=a[r]){
    				if(cnt!=mxK)++cnt;
    				else{--r;break;}
    			}
    		}
    		ans=std::min(ans,n-(r-l+1));
    	}
    	printf("%lld\n",ans);
    	return 0;
    }