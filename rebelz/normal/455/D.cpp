#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,q,blo,cnt;
int st[305],en[305],a[100005],p[100005],bl[100005],num[305][100005],siz[305],lazy[305];
unordered_set<int> s;

int mod(int x,int mod){return x>=mod?x-mod:x;}
int f(int x,int y,int l){return st[l]+mod(x-st[l]+siz[l]-y,siz[l]);}

int main(){
	n=readint();
	blo=400;
	for(int i=1;i<=n;i++) p[i]=a[i]=readint(),s.insert(a[i]);
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++) a[i]=lower_bound(p+1,p+n+1,a[i])-p;
	for(int i=1;i<=n;i+=blo) st[++cnt]=i,en[cnt]=i+blo-1;
	en[cnt]=n;
	for(int i=1;i<=cnt;i++) siz[i]=en[i]-st[i]+1;
	for(int i=1;i<=cnt;i++) for(int j=st[i];j<=en[i];j++) bl[j]=i,num[i][a[j]]++;
	q=readint();
	int opt,x,y,lastans=0;
	while(q--){
//		cout<<"#########################"<<endl;
//		for(int i=1;i<=cnt;i++){
//			for(int j=1;j<=n;j++) cout<<num[i][j]<<' ';
//			cout<<endl;
//		}
//		cout<<"#########################"<<endl;
		opt=readint(); x=(readint()+lastans-1)%n+1; y=(readint()+lastans-1)%n+1;
		if(x>y) swap(x,y);
		if(opt==1){
			int lb=bl[x],rb=bl[y],lt,rt,tmpl,tmpr;
			if(lb==rb) for(int i=y;i>=x+1;i--) swap(a[f(i,lazy[lb],lb)],a[f(i-1,lazy[lb],lb)]);
			else{
				lt=a[f(en[lb],lazy[lb],lb)],rt=a[f(y,lazy[rb],rb)];
				num[rb][rt]--;
				for(int i=y;i>=st[rb]+1;i--) a[f(i,lazy[rb],rb)]=a[f(i-1,lazy[rb],rb)];
				num[rb][a[f(en[rb-1],lazy[rb-1],rb-1)]]++;
				a[f(st[rb],lazy[rb],rb)]=a[f(en[rb-1],lazy[rb-1],rb-1)];
				for(int i=rb-1;i>=lb+1;i--){
					tmpl=f(en[i],lazy[i],i),tmpr=f(en[i-1],lazy[i-1],i-1);
					num[i][a[tmpl]]--,num[i][a[tmpr]]++;
					a[tmpl]=a[tmpr];
					lazy[i]=mod(lazy[i]+1,siz[i]);
				}
				num[lb][lt]--,num[lb][rt]++;
				for(int i=en[lb];i>=x+1;i--) a[f(i,lazy[lb],lb)]=a[f(i-1,lazy[lb],lb)];
				a[f(x,lazy[lb],lb)]=rt;
			}
		}
		else{
			int lb=bl[x],rb=bl[y],ans=0,z=(readint()+lastans-1)%n+1;
			if(!s.count(z)){
				lastans=0;
				printf("0\n");
				continue;
			}
			z=lower_bound(p+1,p+n+1,z)-p;
			ans=0;
			if(lb==rb) for(int i=x;i<=y;i++) ans+=(a[f(i,lazy[lb],lb)]==z);
			else{
				for(int i=x;i<=en[lb];i++) ans+=(a[f(i,lazy[lb],lb)]==z);
				for(int i=st[rb];i<=y;i++) ans+=(a[f(i,lazy[rb],rb)]==z);
				for(int i=lb+1;i<=rb-1;i++) ans+=num[i][z];
			}
			printf("%d\n",lastans=ans);
		}
	}
	return 0;
}