import Data.List
    
solve :: [(Int, Int)] -> [(Int, Int)] -> [(Int, Int)]
solve [] b = b
solve ((valA, indA) : tailA) [] = solve tailA [(valA, indA)]
solve ((valA, indA) : tailA) ((valB, indB) : tailB) = if valB /= valA 
    then solve tailA ((valA, indA) : (valB, indB) : tailB)
    else solve tailA ((valB, indB) : tailB)


main = do
    s <- getLine
    let [n, k] = map (read :: String -> Int) $ words s
    s <- getLine
    let arr = sort $ zip (map (read :: String -> Int) $ words s) [1 .. n]
    let ans = solve arr []
    if (length ans) < k
        then putStrLn "NO"
    else do
        putStrLn "YES"
        putStrLn $ intercalate " " $ map show $ sort $ map (\(x, y) -> y) $ take k ans