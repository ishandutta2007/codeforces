#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	int t=n%2;
	int p1=0,p2=n-1;
	int m1=0,m2=0;
	while (n!=0){
		if (a[p1] >= a[p2]){
			if (n%2==t){
				m1+=a[p1];
				p1+=1;
			}
			else{
				m2+=a[p1];
				p1+=1;
			}
		}
		else{
			if (n%2 == t){
				m1+=a[p2];
				p2--;
			}
			else{
				m2+=a[p2];
				p2--;
			}
		}
		n--;
	}
	cout<<m1<<' '<<m2;
}