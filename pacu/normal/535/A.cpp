#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	if(N==0) cout << "zero";
	if(N==1) cout << "one";
	if(N==2) cout << "two";
	if(N==3) cout << "three";
	if(N==4) cout << "four";
	if(N==5) cout << "five";
	if(N==6) cout << "six";
	if(N==7) cout << "seven";
	if(N==8) cout << "eight";
	if(N==9) cout << "nine";
	if(N==10) cout << "ten";
	if(N==11) cout << "eleven";
	if(N==12) cout << "twelve";
	if(N==13) cout << "thirteen";
	if(N==14) cout << "fourteen";
	if(N==15) cout << "fifteen";
	if(N==16) cout << "sixteen";
	if(N==17) cout << "seventeen";
	if(N==18) cout << "eighteen";
	if(N==19) cout << "nineteen";
	if((N/10)<=1) return 0;
	else if((N/10)==2) cout << "twenty";
	else if((N/10)==3) cout << "thirty";
	else if((N/10)==4) cout << "forty";
	else if((N/10)==5) cout << "fifty";
	else if((N/10)==6) cout << "sixty";
	else if((N/10)==7) cout << "seventy";
	else if((N/10)==8) cout << "eighty";
	else if((N/10)==9) cout << "ninety";
	if(N%10==1) cout << "-one";
	if(N%10==2) cout << "-two";
	if(N%10==3) cout << "-three";
	if(N%10==4) cout << "-four";
	if(N%10==5) cout << "-five";
	if(N%10==6) cout << "-six";
	if(N%10==7) cout << "-seven";
	if(N%10==8) cout << "-eight";
	if(N%10==9) cout << "-nine";
	return 0;
}