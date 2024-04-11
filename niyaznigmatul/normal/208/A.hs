import Data.Char
import Data.List
 
solve :: String -> String
solve = tostr . getlist 

tostr :: [String] -> String
tostr [] = []
tostr (s:[]) = s

tostr (s:t) = s ++ " " ++ (tostr t)


getlist :: String -> [String]
getlist s = filter (\x -> x /= "") $ splitIt "WUB" s

splitIt :: String -> String -> [String]
splitIt delim "" = []
splitIt delim s = splitIt' delim s "" 

splitIt' :: String -> String -> String -> [String]
splitIt' delim [] got = if got /= "" then [got]
                        else []
splitIt' delim s got = if startsWith delim s then 
                        ( if got /= "" then (got :) else ([]++) )
                        (splitIt' delim (skip (length delim) s) "")
                       else 
                       splitIt' delim (tail s) (got++[head s])

skip :: Int -> String -> String
skip 0 b = b
skip a b = skip (a - 1) (tail b)

startsWith :: String -> String -> Bool
startsWith [] t = True
startsWith s [] = False
startsWith s t = if (head s) == (head t) then startsWith (tail s) (tail t)
                            else False

main = do s <- getLine
          putStrLn $ solve s