#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
pair<int,int> a[100005];
int main(){
	int n,la,lb;
	la=lb=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].f;
		a[i].s=i;
	}
	sort(a+1,a+n+1);
	vector <int> v1,v2;
	for(int i=1;i<=n;i++){
		if(la<lb){
			la+=a[i].f;
			v1.push_back(a[i].s);
		}else{
			lb+=a[i].f;
			v2.push_back(a[i].s);
		}
	}
	cout<<v1.size()<<'\n';
	for(int i=0;i<v1.size();i++)
		cout<<v1[i]<<' ';
	cout<<'\n';
	cout<<v2.size()<<'\n';
	for(int i=0;i<v2.size();i++)
		cout<<v2[i]<<' ';
	return 0;
}