#include<iostream>
#include<fstream>
using namespace std;
int main(){
  ifstream ifs("input.txt");
  ofstream ofs("output.txt");
  int n,k,t;
  int i;
  int a[10000];
  ifs>>n>>k;
  for(i=0;i<n;i++){
    ifs>>a[i];
  }
  for(k--;;k++){
    if(k==n)k=0;
    if(a[k]==1)break;
  }
  ofs<<k+1<<endl;
}