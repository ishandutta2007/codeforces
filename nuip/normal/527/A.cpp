#include <iostream> 
#include <string> 
#include <vector> 
#include <cmath> 
#include <algorithm> 
#include <cstdlib> 
#include <ctime> 
#include <cstdio> 
#include <functional> 
#include <set> 
#include <sstream> 
#include <cctype>
#include <stack>
#include <queue>
#include <cstring>
#include <map>
#include <list>

using namespace std; 

long long res;
long long gcd(long long a,long long b){
	if(b==0) return a;
	else{
		res+=a/b;
		gcd(b,a%b);
	}
}

int main(){

	long long a,b;
	cin>>a>>b;
	gcd(a,b);
	cout<<res<<endl;

	return 0;

}