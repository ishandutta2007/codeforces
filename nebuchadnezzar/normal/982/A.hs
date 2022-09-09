isMaximal :: String -> Bool
isMaximal "0" = False
isMaximal ('0' : '0' : tail) = False
isMaximal ('1' : '1' : tail) = False
isMaximal ('2' : '0' : '0' : tail) = False
isMaximal ('0' : '1' : tail) = isMaximal ('1' : tail)
isMaximal ('1' : '0' : tail) = isMaximal ('2' : tail)
isMaximal ('2' : '0' : tail) = isMaximal ('0' : tail)
isMaximal ('2' : '1' : tail) = isMaximal ('1' : tail)
isMaximal _ = True



main = do
    n <- getLine
    s <- getLine
    putStrLn $ 
        if isMaximal s
            then "Yes"
            else "No"