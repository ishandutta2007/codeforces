import Control.Monad
import Control.Applicative
import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Array

readInt :: IO Int
readInt = read <$> getLine
readIntList :: IO [Int]
readIntList = fmap read . words <$> getLine
readIntArray :: Int -> IO (Array Int Int)
readIntArray n = listArray (0, n-1) <$> readIntList
readSortedIntArray :: Int -> IO (Array Int Int)
readSortedIntArray n = listArray (0, n-1) . sort <$> readIntList

squares :: [Int]
squares = flip fmap [1..] $ \i -> i * i

squareRoot :: Int -> Either Int Int
squareRoot x = squareRootImpl 1 x
  where
    squareRootImpl lo hi =
      if lo >= hi
        then
          case (lo * lo) `compare` x of
            LT -> Left $ lo
            EQ -> Right lo
            GT -> Left $ lo - 1
        else
          let mid = (lo + hi) `div` 2 in
          case (mid * mid) `compare` x of
            LT -> squareRootImpl (mid + 1) hi
            EQ -> Right mid
            GT -> squareRootImpl lo (mid - 1)

squareSum :: [[Int]]
squareSum = flip fmap [1..] $ \x ->
  case squareRoot x of
    Right y -> [y]
    Left y -> foldr1 (\l l' -> if (length l) < (length l') then l else l') $ flip fmap [1..y] (\i -> (i:)$ squareSum !! (x-i*i-1))

squareSumN :: [Int]
squareSumN = fmap length squareSum

smallS :: [[Int]]
smallS =
  [ [1]
  , [3, 4]
  , [3, 4, 12]
  , [3, 4, 12, 84]
  ]

main :: IO ()
main = do
  [n, m] <- readIntList
  let sn = squareSum !! (n-1)
  let pn = product sn
  let sn' = smallS !! (length sn - 1)
  let sm = squareSum !! (m-1)
  let pm = product sm
  let sm' = smallS !!(length sm - 1)
  forM_ [0..length sn - 1] $ \n' -> do
    let ni = (sn!!n')
    forM_ [1..(sn!!n')*(sn!!n')] $ \_ -> do
      forM_ [0..length sm - 1] $ \m' -> do
        let mi = (sm!!m')
        forM_ [1..(sm!!m')*(sm!!m')] $ \_ -> do
          putStr $ show ((sn'!!n')*(pn `div` ni)*(sm'!!m')*(pm `div` mi)) ++ " "
      putStrLn ""