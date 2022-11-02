#include<map>

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<queue>
using namespace std;

priority_queue<long long> num; 
long long hit(long long n){
	long long ret=0;
	
	if(n!=1) ret+= n*(n-1)/2 ;
	
	return ret;
}



int main(){
	long long n;
	
	scanf("%I64d",&n);
		
	for(int k=0;k<=60;k++ ){
		long long toet = pow(2,k)-1;
		long long l=1;
		long long r= min(2000000000000000000LL/(toet+1), (long long)sqrt(2000000000000000000LL));
		
		while(l<=r){
			long long m = (l+r)/2;
			long long cek = m*2 -1;
			long long tmp = hit(cek) + cek*(toet);
			
			//printf("%I64d\n",m);
			if(tmp < 0) r = m-1;
			else {
				if(tmp < n) l = m+1; else r = m-1; 
			}
		}
		l = 2*l -1;
		long long tmp = hit(l) + l*toet;
		
		toet++;
		if(tmp == n) num.push(-1*l*toet);
	}
	
	if(num.empty()) printf("-1\n");
	while(!num.empty()){
		printf("%I64d\n",-num.top());
		num.pop();
	}
	
	return 0;
}