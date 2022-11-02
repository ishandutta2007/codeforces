#include<iostream>
int n;
int main(){
	std::cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)std::cout<<(i==j?0:1+(i==n-1||j==n-1?2*i+2*j:i+j)%(n-1))<<' ';
		puts("");
	}
    return 0;
}