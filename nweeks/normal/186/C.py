N = int(input())
result = (pow(2, N, int(1e9 + 7)) * (pow(2, N, int(1e9 + 7)) + 1)) % int(1e9+7)
result = (result * pow(2, int(1e9+5), int(1e9+7))) % int(1e9+7)
print(result)