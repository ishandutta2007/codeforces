#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

int main(){
  int a,b;
  vector<int> home,guest;
  int num;
  scanf("%d",&num);

  for(int i=0;i<num;i++){
    scanf("%d %d",&a,&b);
    home.push_back(a);
    guest.push_back(b);
  }
  
  int sum=0;
  
  for(int i=0;i<num;i++){
    for(int j=0;j<num;j++){
      sum+=(home[i]==guest[j]);
    }
  }

  cout<<sum<<endl;

  return 0;
}