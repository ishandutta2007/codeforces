import Data.Char
import Data.List
 
count :: String -> Char -> Int
count s c = length $ filter (\x -> x == c) s

solve :: Int -> String -> String
solve k s = let z = getIt s 'a' 'z' k in if z == "-1" then z else repeat' k z

repeat' :: Int -> String -> String
repeat' 0 s = ""
repeat' a s = s ++ (repeat' (a - 1) s)

getIt :: String -> Char -> Char -> Int -> String
getIt s c to k = if c > to then "" else
                if mod (count s c) k /= 0 then "-1" else
                 let
                     z = getIt s (toEnum(fromEnum(c) + 1)) to k
                     u = count s c
                 in
                   if z == "-1" then z
                       else (replicate (div u k) c) ++ z 
main = do n <- getLine
          s <- getLine
          putStrLn $ solve (read n) s