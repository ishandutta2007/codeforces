#include <iostream>
using namespace std;
 
int main() {
int n,t;
cin >> n >> t;
if(t < 10){
for(int i = 0;i<n;i++){
cout << t;
}
}
else{
if(n == 1){
cout << -1;
}
else{
for(int i = 0;i<n-1;i++){
cout << 1;
}
cout << 0;
}
}
return 0;
}