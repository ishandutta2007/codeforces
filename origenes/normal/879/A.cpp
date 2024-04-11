#include <iostream>
using namespace std;
int n, s, d, cur;
int main(){
	cin>>n;
	cin>>s>>d;
	cur=s;
	for(int i=2; i<=n; i++){
		cin>>s>>d;
		if(s==cur+1){
			cur++;
			continue;
		}
		if(s>cur+1){
			cur=s;
			continue;
		}
		int k;
		for(k=1; ; k++)
			if(s+k*d>=cur+1) break;
		cur=s+k*d;
	}
	cout<<cur<<endl;
	return 0;
}