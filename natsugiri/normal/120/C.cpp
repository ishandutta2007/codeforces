#include<iostream>
#include<fstream>
using namespace std;
int main(){
  int n,i,j,r;
  ifstream ifs("input.txt");
  ofstream ofs("output.txt");
  int k;
  ifs>>n>>k;
  r=0;
  for(i=0;i<n;i++){
    ifs>>j;
    if(j>3*k)r+=j-3*k;
    else r+=j%k;
  }
  ofs<<r<<endl;
}