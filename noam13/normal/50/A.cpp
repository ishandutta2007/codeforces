#include <iostream>
#include <vector>
using namespace std;
 
int main(){
   int n,m;
   cin >> n >> m;
   if (n%2==0 || m%2==0) cout << (n*m)/2 << endl;
   else cout << (n*m-1)/2 << endl;
   return 0;
}