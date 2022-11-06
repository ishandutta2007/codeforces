#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main() {
    int n;
    int minv = 100, mini = -1, maxv = 0, maxi = -1;
    cin >> n;
    for(int i = 0; i < n; i++) {
    	int m; cin >> m;
    	if(m <= minv) {
    		minv = m;
    		mini = i;
    	} 
    	if(m > maxv) {
    		maxv = m;
    		maxi = i;
    	}
    }
    if(maxi > mini) cout << maxi + n - mini - 2;
    else cout << maxi + n - mini - 1;
    cin >> n;
    return 0;
}