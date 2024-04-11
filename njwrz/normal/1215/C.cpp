#include <bits/stdc++.h>
#define ll long long
using namespace std;
int l,a[200005],b[200005],la,lb;
string x,y;
int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	cin>>l>>x>>y;
	for(int i=0;i<l;i++){
		if(x[i]=='a'&&y[i]=='b'){
			a[++la]=i+1;
		}else if(x[i]=='b'&&y[i]=='a'){
			b[++lb]=i+1;
		}
	}
	if((la+lb)&1)cout<<-1;
	else{
		if(la%2==1){
			cout<<((la+lb)>>1)+1<<'\n';
			for(int i=2;i<=la;i+=2){
				cout<<a[i-1]<<' '<<a[i]<<'\n';
			}
			cout<<a[la]<<' '<<a[la]<<'\n';
			cout<<a[la]<<' ';
			cout<<b[1]<<'\n';
			for(int i=2;i<=lb;i+=2)cout<<b[i]<<' '<<b[i+1]<<'\n';
		}else{
			cout<<((la+lb)>>1)<<'\n';
			for(int i=2;i<=la;i+=2){
				cout<<a[i-1]<<' '<<a[i]<<'\n';
			}
			for(int i=2;i<=lb;i+=2){
				cout<<b[i-1]<<' '<<b[i]<<'\n';
			}
		}
	}
	return 0;
}