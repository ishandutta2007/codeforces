import Data.Char
 
cmp :: String -> String -> String
cmp s t = if (s < t) then "-1" else
        if (t < s) then "1" else "0"
        
main = do s <- getLine
          t <- getLine
          s <- return $ map toUpper s
          t <- return $ map toUpper t
          putStrLn $ cmp s t