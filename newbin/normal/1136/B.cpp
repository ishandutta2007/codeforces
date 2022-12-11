#include<iostream>
using namespace std;
const int maxn = 150;
int l[maxn],r[maxn];
int main(){
	int n,k;
	cin>>n>>k;
	cout<<3*n + min(k-1,n-k)<<endl;
}