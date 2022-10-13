#include <string>
#include <iostream>

int main () {
	std::string s;
	std::cin >> s;
	
	int ans = 0;
	for (int i=0; i<s.length(); i++) {
		int i1 = ('@' < s[i]) && ('[' > s[i]);		
		int i2 = ('`' < s[i]) && ('{' > s[i]);
		
		if (isalpha(s[i]))
			ans += i1 * (tolower(s[i]) - 'a' + 1) - i2 * (tolower(s[i]) - 'a' + 1);
	}
	
	std::cout << ans << std::endl;
	return 0;
}