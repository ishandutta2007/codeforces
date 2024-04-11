#include <iostream>
using namespace std;
int num[12], n, x, res[12];
char op;
void AND(){
	for(int i=0; i<10; i++)
		if(!((1<<i)&x)) num[i]=0;
}
void OR(){
	for(int i=0; i<10; i++)
		if((1<<i)&x) num[i]=1;
}
void XOR(){
	for(int i=0; i<10; i++){
		if(num[i]==2||num[i]==-2) num[i]=(1<<i)&x?-num[i]:num[i];
		else if(num[i]==0) num[i]=(1<<i)&x?1:0;
		else num[i]=(1<<i)&x?0:1;
	}
}
int main(){
	cin>>n;
	for(int i=0; i<10; i++)
		num[i]=res[i]=2;
	for(int i=1; i<=n; i++){
		cin>>op>>x;
		if(op=='|') OR();
		else if(op=='&') AND();
		else XOR();
	}
	int o1=0, o2=0, ex1=0, ex2=0;
	for(int i=0; i<10; i++){
		if(!num[i]) o1+=1<<i, ex1+=1<<i;
		else if(num[i]==1) o2+=1<<i;
		else if(num[i]==-2) ex2+=1<<i;
	}
	cout<<4<<endl;
	cout<<"| "<<o1<<endl;
	cout<<"^ "<<ex1<<endl;
	cout<<"| "<<o2<<endl;
	cout<<"^ "<<ex2<<endl;
	return 0;
}