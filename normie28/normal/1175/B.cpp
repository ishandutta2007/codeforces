#include<iostream>
#include<stack>
#include<cmath>
 
using namespace std;
 
stack<int> forCmd;
 
long long maxValue = pow(2, 32) - 1;
 
int main() {
  int l;
 
  cin >> l;
 
  stack<long long> result;
 
  result.push(0);
 
  while(l--) {
    string cmd;
 
    cin >> cmd;
 
    if (cmd == "add") {
      long long lastResult = result.top();
      result.pop();
 
      long long newResult = ++lastResult;
 
      result.push(newResult);
    } else if (cmd == "for") {
      int loop;
      cin >> loop;
      
      forCmd.push(loop);
      result.push(0);
    } else {
      int n = forCmd.top();
      forCmd.pop();
      
      long long lastResult = result.top();
      result.pop();
 
      long long newResult = n * lastResult;
      long long secondLast = result.top();
      result.pop();
 
      result.push(newResult + secondLast);
    }
 
    if (result.top() > maxValue) {
      cout << "OVERFLOW!!!" << endl;
 
      return 0;
    }
  }
 
  long long finalResult = result.top();
 
  cout << finalResult << endl;
}