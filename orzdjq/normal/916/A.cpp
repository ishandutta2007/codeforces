#include<bits\stdc++.h>
using namespace std;
bool checkgood(int x){
	if ((x/60)%10==7) return true;
	if (x%60%10==7) return true;
	return false;
} 
int main(){
	int l;
	cin>>l;
	int h,m;
	cin>>h>>m;
	int t=h*60+m;
	int ans=0;
	while (1){
		if (checkgood(t)) break;
		ans++;
		t-=l;
		if (t<0) t+=1440;
	}
	cout<<ans<<endl;
}