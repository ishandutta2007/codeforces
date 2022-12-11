    #include <iostream>
    using namespace std;
     
    int main() {
    	int n;
    	cin >> n;
    	int sk = 0;
    	char a,b,c;
    	for(int x = 0;x<n;x++){
    		cin >> a >> b >> c;
    		if(a == '+' || b == '+' || c == '+'){
    			sk++;
    		}
    		else{
    			sk--;
    		}
    	}
    	cout << sk;
    	return 0;
    }