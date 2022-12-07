#include <bits/stdc++.h>

using namespace std;

string num[900] = { "one",
"two",
"three",
"four",
"five",
"six",
"seven",
"eight",
"nine",
"ten"};

string root[10] = {"twenty", 
"thirty",
"forty",
"fifty",
"sixty",
"seventy",
"eighty",
"ninety",
"ten"};

void out(string ans){
	cout << ans;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	int a; cin >> a;

	if(a == 0){
		cout << "zero";
		return 0;
	}

	if(a <= 10){
		cout << num[a - 1] << endl;
	}
	else{
		if(a < 20){
			if(a == 11){
				out("eleven");	
			}	
			if(a == 12){
				out("twelve");
			}
			if(a == 13){
				out("thirteen");
			}
			if(a == 14){
				out("fourteen");
			}
			if(a == 15){
				out("fifteen");
			}
			if(a == 16){
				out("sixteen");
			}
			if(a == 17){
      	out("seventeen");
      }
      if(a == 18){
      	out("eighteen");
      }
      if(a == 19){
      	out("nineteen");
      }
		}
		else{
			int big = a / 10;
			cout << root[big - 2];
			if(a % 10 != 0){
				cout << "-" << num[a % 10 - 1];
			}
		}
	}

	return 0;
}