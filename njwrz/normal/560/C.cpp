#include <bits/stdc++.h>
using namespace std;
int a[7];
int main(){
	for(int i=1;i<=6;i++)cin>>a[i];
    cout<<(a[3]+a[4]+a[5])*(a[3]+a[4]+a[5])
	-a[1]*a[1]-a[3]*a[3]-a[5]*a[5];
	return 0;
}