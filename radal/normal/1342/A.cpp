#include <iostream>
#include <cmath>
using namespace std;
/*
void msort(int l,int r){
	if (r-l==1){
		return;
	}
	int mid = (l+r)/2;
	msort(l, mid);
	msort(mid, r);
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
			if (a[p1]>a[p2]){
				tt++;
				cout<<a[p1]<<a[p2]<<endl;
		}
		}
	}
	for (int i=l; i<r; i++){
		a[i]=b[i];
	}
}*/
struct node{
	char val;
	node* p;
};

int main(){
	int t;
	cin >> t;
	for (int i=0; i<t; i++){
		long long int x,y,a,b,m=0,M;
		cin >> x >> y;
		cin >> a >> b;
		if (b <= 2*a){
			m+= min(x,y)*b;
			M = min(x,y);
			x -= M;
			y -= M;
			if (x>0){
				m+=x*a;
			}
			if (y>0){
				m+=y*a;
			}
		}
		else{
			m+=(x+y)*a;
		}
		cout << m << endl;
	}
}