if __name__ == "__main__":

    q = int(input())
    while q > 0:
        q = q - 1
        n = int(input())
        line = input()
        arr = line.split(" ")
        sum = 0
        for x in arr:
            if int(x) <= (1 << 11):
                sum = sum + int(x)
        #print(n, sum, (1 << 11), sep = " ")
        if sum >= (1 << 11):
            print("YES")
        else:
            print("NO");