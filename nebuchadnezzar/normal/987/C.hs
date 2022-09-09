import Data.List
    
addLists :: [Int] -> [Int] -> [Int]
addLists a b = map (\(x, y) -> x + y) $ zip a b

getBest :: [(Int, Int)] -> Int -> Int
getBest [] _ = 400000000
getBest ((a, b) : tail) sz = if sz > a then min b $ getBest tail sz else getBest tail sz

solve :: [Int] -> [Int] -> [(Int, Int)] -> [Int]
solve [] [] [] = []
solve (a : tailA) (b : tailB) c = (getBest c a) : solve tailA tailB ((a, b) : c)
solve _ _ _ = []

main = do
    s <- getLine
    let n = read s :: Int
    s <- getLine
    let szs = map (read :: String -> Int) $ words s
    s <- getLine
    let costs = map (read :: String -> Int) $ words s
    let bestlr = solve szs costs []
    let bestrl = reverse $ solve (reverse $ map negate szs) (reverse costs) []
    let ans = minimum $ addLists costs $ addLists bestlr bestrl
    print $ if ans < 400000000 then ans else -1