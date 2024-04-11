#include<iostream>
#include<fstream>
using namespace std;
int main(){
  ifstream ii("input.txt");
  ofstream oo("output.txt");
  int t,n;
  ii>>t;
  for(;t--;){
    ii>>n;n=n%2?0:1;
    oo<<n<<endl;
  }
}