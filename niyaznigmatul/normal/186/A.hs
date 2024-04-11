import Data.Char
import Data.List
 
count :: String -> Char -> Int
count s c = length $ filter (\x -> x == c) s

cs :: String -> String -> Bool
cs s1 s2 = cs' s1 s2 'a' 'z'

cs' :: String -> String -> Char -> Char -> Bool
cs' s1 s2 c to = if c > to then True else
                  if (count s1 c) /= (count s2 c) then False else
                   cs' s1 s2 (toEnum ((fromEnum c) + 1)) to

bad :: String -> String -> Int
bad [] [] = 0
bad [] s = 10
bad s [] = 10
bad s t = (bad (tail s) (tail t)) + (if (head s) == (head t) then 0 else 1)

solve :: String -> String -> String
solve s1 s2 = if ((bad s1 s2) <= 2) && (cs s1 s2) then "YES" else "NO" 

main = do s1 <- getLine
          s2 <- getLine
          putStrLn $ solve s1 s2