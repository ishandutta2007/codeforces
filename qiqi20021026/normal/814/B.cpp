#include<iostream>
#include<cstdio>

using namespace std;

#define LL long long

int n,t1,t2,p1,p2,a[1030],b[1030];
bool p[1030];

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	
	for (int i=1;i<=n;i++)
		if (a[i]==b[i]){
			p[a[i]]++;
		}
		else{
			t2=t1;
			t1=i;
		}
		
	for (int i=1;i<=n;i++)
		if (p[i]!=1){
			p2=p1;
			p1=i;
		}
	
	if (t2!=0){	
		if (a[t1]==p1 && b[t1]!=p1 && b[t2]==p2 && a[t2]!=p2)
			a[t2]=p2;
		else{
			if (a[t1]==p2 && b[t1]!=p2 && b[t2]==p1 && a[t2]!=p1)
				a[t2]=p1;
			else{
				if (a[t2]==p1 && b[t2]!=p1 && b[t1]==p2 && a[t1]!=p2)
					a[t1]=p2;
				else{
					a[t1]=p1;
				}
			}
		}
	}

	else a[t1]=p1;
	
	
	for (int i=1;i<=n;i++) printf("%d ",a[i]);
	
	return 0;
}