#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;
int a,b,c,d,e,a1,a2;

int main(){
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	a1=max(0,e-a*(c-1)-b*(d-1));
	if (c>d){
		swap(c,d);
		swap(a,b);
	} 
	if (e<=a*c){
		a2=e/c;
	}
	else{
		a2=a+(e-a*c)/d;
	}
	cout<<a1<<" "<<a2<<endl;
}