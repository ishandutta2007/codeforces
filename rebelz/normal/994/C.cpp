#include<iostream>
#include<algorithm>

using namespace std;

struct node{
	int p[5];
	bool operator<(const node comp){
		if(p[1]+p[2]==comp.p[1]+comp.p[2])
			return p[1]<comp.p[1];
		return p[1]+p[2]<comp.p[1]+comp.p[2];
	}
}a[10],b[10];

bool in(int x,int y,int k){
	if(k==1){
		if(x<=a[4].p[1]&&x>=a[1].p[1]&&y<=a[4].p[2]&&y>=a[1].p[2])
			return true;
		return false;
	}
	else{
		if(x<=b[2].p[1]&&x>=b[1].p[1]&&x+b[1].p[2]-b[1].p[1]>=y&&-x+b[1].p[1]+b[1].p[2]<=y)
			return true;
		else if(x>=b[2].p[1]&&x<=b[4].p[1]&&-x+b[4].p[1]+b[4].p[2]>=y&&x+b[4].p[2]-b[4].p[1]<=y)
			return true;
		return false;
	}
}

int main(){
	for(int i=1;i<=4;i++)
		for(int j=1;j<=2;j++)
			cin>>a[i].p[j];
	for(int i=1;i<=4;i++)
		sort(a+1,a+5);
	for(int i=1;i<=4;i++)
		for(int j=1;j<=2;j++)
			cin>>b[i].p[j];
	for(int i=1;i<=4;i++)
		sort(b+1,b+5);
	for(int i=-100;i<=100;i++){
		for(int j=-100;j<=100;j++){
			if(in(i,j,1)&&in(i,j,2)){
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}