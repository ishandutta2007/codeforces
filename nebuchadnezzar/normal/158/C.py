num = int(raw_input())

stack = [""] * 600
index = 1

for i in xrange(num):
    q = raw_input()
    if(q == "pwd"):
        inp = ""
        for j in xrange(index):
            inp = inp + stack[j] + "/"
        print inp
    else:
        q = q.split()
        adress = q[1]
        if(adress == "/"):
            index = 1
        elif(adress[0] == "/"):
            adress = adress.split("/")
            index = 0
            for k in adress:
                if(k == ".."):
                    index -= 1
                else:
                    stack[index] = k
                    index += 1
                 
        else:
            adress = adress.split("/")
            for k in adress:
                if(k == ".."):
                    index -= 1
                else:
                    stack[index] = k
                    index += 1