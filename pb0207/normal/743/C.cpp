#include<iostream>  
#include<cstdio>  
#include<cstring>  
  
using namespace std;  
  
int n;
  
int main()  
{  
	cin>>n;
    if(n==1) 
		cout<<-1;
    else 
		cout<<n<<" "<<n+1<<" "<<n*(n+1);
}