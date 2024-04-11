import Data.List

solve :: [(Int, Int)] -> [(Int, Int)] -> String -> [Int]
solve [] [] [] = []
solve ((valA, indA) : tailA) b ('0' : tailS) = indA : solve tailA ((valA, indA) : b) tailS
solve a ((valB, indB) : headB) ('1' : tailS) = indB : solve a headB tailS
solve _ _ _ = []

main = do
    s <- getLine
    let n = read s :: Int
    s <- getLine
    let weights = map (read::String->Int) (words s)
    s <- getLine
    let arr = sort $ zip weights [1..]
    let ans = solve arr [] s
    putStrLn $ intercalate " " $ map show ans