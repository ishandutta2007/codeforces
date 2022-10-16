#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k; 
int main(){
	scanf("%I64d%I64d",&n,&k);
	printf("%I64d\n",(k+n-1)/n);
}