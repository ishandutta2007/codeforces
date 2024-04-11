#include<bits/stdc++.h>
using namespace std;
int p[300],f[300]; 
int main(){
	int q,k,i,l;
	string a,b,c;
	cin>>q;
	for(k=0;k<q;k++){
		cin>>a>>b>>c;
		bool ans=1;
		memset(f,0,sizeof(f));
		for(i=0;i<300;i++)p[i]=0;
		l=0;
		for(i=0;i<a.size();i++){
			while(l<b.size()&&b[l]!=a[i])l++;
			l++;
			if(b[l-1]==a[i]){
				f[l-1]=1;
			}else{
				cout<<"NO"<<endl;ans=0;break;
			}
		}
		if(!ans)continue;
		for(i=0;i<c.size();i++)p[c[i]]++;
		for(i=0;i<b.size();i++){
			if(!f[i]){
				if(p[b[i]]){
					p[b[i]]--;
				}else{
					cout<<"NO"<<endl;ans=0;break;
				}
			}
			if(!ans)break;
		}
		if(ans)cout<<"YES"<<endl;
	}
	return 0;
}