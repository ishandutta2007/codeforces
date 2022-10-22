#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"

using namespace std;
int a,b,c;
int box;

int main(){
	cin >> a >> b >> c;
	cout << (c - 1) / (b * 2) + 1 << " " << ((c - 1) % (b * 2)) / 2 + 1 << " ";
	if (c % 2)cout << "L\n";
	else cout << "R\n";

	return 0;
}