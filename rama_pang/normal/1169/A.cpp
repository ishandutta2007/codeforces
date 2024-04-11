#include <iostream>
using namespace std;

int main(){
	int n,a,b,x,y;
	cin >> n >> a >> x >> b >> y;
	int ak,bk;
	if(a>1) ak=a-1;
	if(a==1) ak=n;
	if(b<n) bk=b+1;
	if(b==n) bk=1;
	while(a!=ak and b!=bk){
		if(a==b){
			cout << "YES\n";
			return 0;
		}
		
		if(a<n){
			a++;
		} else if(a==n){
			a=1;
		}
		if(b>1){
			b--;
		} else if(b==1){
			b=n;
		}
		
		if(a==x or b==y){
			if(a==b){
			cout << "YES\n";
			return 0;
			}
			break;
		}
	}
	cout << "NO\n";
	return 0;
}