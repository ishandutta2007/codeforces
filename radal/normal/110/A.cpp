#include <iostream>
#include <algorithm>
using namespace std;
void msort(int l,int r,int* a){
	int b[10000];
	if (r-l==1){
		return;
	}
	int mid = (l+r)/2;
	msort(l, mid, a);
	msort(mid, r, a);
	int p1,p2;
	p1 = l;
	p2 = mid;
	for (int i=l; i<r; i++){
		if (p2>=r || (a[p1]<a[p2] and p1<mid)){
			b[i] = a[p1];
			p1++;
		}
		else{
			b[i] = a[p2];
			p2++;
		}
	}
	for (int i=l; i<r; i++){
		a[i]=b[i];
	}
}

bool lucky(int s){
	bool f=1;
	if (s==0){
		return 0;
	}
	while (s>0){
		if (s%10 != 4 and s%10 != 7){
			return 0;
		}
		s/=10;
	}
	return f;
}
int main(){
	long long int n,i=1,t=0;
	cin>>n;
	while (n>0){
		if (lucky(n%10)){
			t+=1;
		}
		i++;
		n/=10;
	}
	if (lucky(t))
	cout<<"YES"	;
	else{
		cout<<"NO";
	}
}