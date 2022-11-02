#include <iostream>

using namespace std;

/*bool check(int n,int x,int y, int a[24][24]){
	int j=1;
	for (int i=0; i<n; i++){
		if (a[i][y]==1 and i!=x){
			//cout<<1;
			return 0;
		}
		if (a[x][i]==1 and i!=y){
			cout<<a[3][0];
			return 0;
		}
	}
	while (x-j>=0 and y-j>=0){
		if (a[x-j][y-j]==1){
			return 0;
		}
		j+=1;
	}
	j=1;
	while (x+j<n and y+j<n){
		if (a[x+j][y+j]==1){
			return 0;
		}
		j+=1;
	}
	j=1;
	while (x-j>=0 and y+j<n){
		if (a[x-j][y+j]==1){
			return 0;
		}
		j+=1;
	}
	j=1;
	while (x+j<n and y-j>=0){
		if (a[x+j][y-j]==1){
			return 0;
		}
		j+=1;
	}
	return 1;
}
int vaz(int n,int m, int a[24][24]){
	long long int t=0;
	//cout<<m<<"m::"<<endl;
	if (m==1){
		for (int i=0; i<n; i++){
			if (check(n,n-1,i,a)){
				t+=1;
				//cout<<a[0][0]<<a[1][1]<<endl;
			}
		}
	//	cout<<t<<endl;
		return t;
	}
	else{
		for (int i=0; i<n; i++){
			if (check(n,n-m,i,a)){
				a[n-m][i]=1;
				//cout<<'n'<<' '<<n<<"m: "<<m<<endl;
				t+=vaz(n,m-1,a);
				a[n-m][i]=0;
			}
		}
		return t;
	}
}*/

int main(){
	string s;
	cin>>s;
	if (int(s[0])<=int('Z') and int(s[0])>=int('A')){
		cout<<s;
	}
	else{
		s[0]=char(int(s[0])+int('A')-int('a'));
		cout<<s;
	}
}