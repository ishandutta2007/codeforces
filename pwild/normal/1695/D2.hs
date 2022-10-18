{-# LANGUAGE ScopedTypeVariables, TupleSections #-}
import Control.Monad
import Data.Bits
import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as B
import Data.Array.Unboxed
import qualified Data.IntSet as S

solve :: Int -> [[Int]] -> Int
solve n edges
  | n == 1     = 0
  | isBamboo   = 1
  | otherwise  = length leaves - numBranches
  where
    deg :: UArray Int Int
    deg = accumArray (+) 0 (0,n-1) $ map (,1) $ concat edges

    adj :: UArray Int Int
    adj = accumArray xor 0 (0,n-1) $ concatMap (\[a,b] -> [(a,b),(b,a)]) edges

    rise :: Int -> Int
    rise a = go a (adj ! a)
      where
        go a b = if deg ! b >= 3 then b else go b (adj ! b `xor` a)
    
    isBamboo = maximum (elems deg) <= 2
    leaves = filter (\x -> deg ! x == 1) [0 .. n-1]
    numBranches = S.size $ S.fromList $ map rise leaves

readInts :: IO [Int]
readInts = map (fst  . fromJust . B.readInt) . B.words <$> B.getLine

main :: IO ()
main = do
  [tc] <- readInts
  replicateM_ tc $ do
    [n] <- readInts
    edges <- replicateM (n-1) $ map (-1+) <$> readInts
    print $ solve n edges