#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

double n,m;
double a[1005],b[1005];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cout<<-1<<endl;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]==1){
			cout<<-1<<endl;
			return 0;
		}
	}
	double ans=0;
	ans+=m/(b[1]-1);
	m+=m/(b[1]-1);
	for(int i=n;i>=2;i--){
		ans+=m/(a[i]-1);
		m+=m/(a[i]-1);
		ans+=m/(b[i]-1);
		m+=m/(b[i]-1);
	}
	ans+=m/(a[1]-1);
	m+=m/(a[1]-1);
	printf("%.10lf\n",ans);
	return 0;
}