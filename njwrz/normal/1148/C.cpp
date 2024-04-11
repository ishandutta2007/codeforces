#include<bits/stdc++.h>
using namespace std;
int f[300005];
int tf[300005],ta[300005];
int main(){ 
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,a[300005],t,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];f[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		tf[i]=f[i];
		ta[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		if(f[i]!=i){
			if(i<=n/2){
				if(f[i]<=n/2){
					ans+=3;
					t=f[i];
					f[a[i]]=f[i];f[i]=i;swap(a[i],a[t]);
				}else{
					if(i==1){
						ans++;
					}else{
						ans+=5;
					}
					t=f[i];
					f[a[i]]=f[i];f[i]=i;swap(a[i],a[t]);
				}
			}else {
				ans+=3;
				t=f[i];
				f[a[i]]=f[i];f[i]=i;swap(a[i],a[t]);
			}
		}
	}
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++){
		f[i]=tf[i];a[i]=ta[i];
	}
	for(int i=1;i<=n;i++){
		if(f[i]!=i){
			if(i<=n/2){
				if(f[i]<=n/2){
					cout<<f[i]<<' '<<n<<'\n';
					cout<<i<<' '<<n<<'\n';
					cout<<f[i]<<' '<<n<<'\n';
					t=f[i];
					f[a[i]]=f[i];f[i]=i;swap(a[i],a[t]);
				}else{
					if(i==1){
						cout<<1<<' '<<f[i]<<'\n';
					}else{
						cout<<1<<' '<<f[i]<<'\n';
						cout<<i<<' '<<n<<'\n';
						cout<<1<<' '<<n<<'\n';
						cout<<i<<' '<<n<<'\n';
						cout<<1<<' '<<f[i]<<'\n';
					}
					t=f[i];
					f[a[i]]=f[i];f[i]=i;swap(a[i],a[t]);
				}
			}else {
				cout<<1<<' '<<i<<'\n';
				cout<<1<<' '<<f[i]<<'\n';
				cout<<1<<' '<<i<<'\n';
				t=f[i];
				f[a[i]]=f[i];f[i]=i;swap(a[i],a[t]);
			}
		}
	}
	return 0;
}