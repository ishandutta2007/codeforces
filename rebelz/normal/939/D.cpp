#include<iostream>

using namespace std;

int n;
int f[30];
char s1[100005],s2[100005],ansx[100005],ansy[100005];

int getfather(int v){
	if(v==f[v])
		return v;
	return f[v]=getfather(f[v]);
}

int main(){
	cin>>n>>s1+1>>s2+1;
	int fx,fy,ans=0;
	for(int i=1;i<=26;i++)
		f[i]=i;
	for(int i=1;i<=n;i++){
		fx=getfather(s1[i]-'a'+1);
		fy=getfather(s2[i]-'a'+1);
		if(fx!=fy){
			f[fx]=fy;
			ans++;
			ansx[ans]=s1[i];
			ansy[ans]=s2[i];
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=ans;i++)
		cout<<ansx[i]<<' '<<ansy[i]<<endl;
	return 0;
}