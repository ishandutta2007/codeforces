#include <bits/stdc++.h>
#define IOS cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
 
using namespace std;
 
char in[1 << 27];
char const* o ;
 
void load(){  o = in;   in [   fread(in,  1,  sizeof(in ) - 4 ,  stdin ) ] = 0; }
 
int readInt(){
      int u = 0;
      
      while( *o && *o <= 32) ++o ; //  skip spaces
    
      while ( *o >='0' && *o <='9') u = (u << 3) + (u << 1) + (*o++ -'0');
      return u;
}
 
int A[1000000], B[1000000];
int32_t main(){
    load();
	int n, m, p;
	n = readInt(), m = readInt(), p = readInt();
	for(int i = 0; i < n; i++){
		A[i] = readInt();
	}
	for(int i = 0; i < m; i++){
		B[i] = readInt();
	}
	
	int i = 0, j = 0;
	while(true){
		if(A[i] % p == 0){
			i++;
			continue;
		}else if(B[j] % p == 0){
			j++;
			continue;
		}else{
		    break;
		}
	}
	cout << i + j << endl;
}